import { useEffect, useState } from 'react';
import './App.css';
import WasmModule from "./wasm/starter-wasm.js";
import { useRef } from "react";
import CanvasPanel from './CanvasPanel.js';
import WasmSetup, { WasmInterface } from './WasmSetup.js';

let loadingStarted = false;

let wasmModule: WasmInterface | null = null;

function loadWasm() {
  if (loadingStarted) return;
  loadingStarted = true;

  (globalThis as any).portalToCC = {
    uuid: function() : string {
      return "c98b-90ca-8821-09fe";
    },
    atob: function(arg: string) : string {
      return window.atob(arg);
    },
  };
  window.setTimeout(async () => {
    const mod = await WasmModule();
    console.log(mod);
    wasmModule = mod as WasmInterface;
  }, 100);

}

function App() {
  const [text, setText] = useState("-");
  const canvasRef = useRef<HTMLCanvasElement>(null);
  let wasmModule: WasmInterface | null = null;

  useEffect(() => {
    if (wasmModule) return;
    const timeoutId = globalThis.setTimeout(async () => {
      wasmModule = await WasmSetup.awaitModuleLoaded();
      console.log(wasmModule);
    }, 0);
    return () => { globalThis.clearTimeout(timeoutId) };
  }, []);

  const onClickBtn = () => {
    if (!wasmModule) {
      return;
    }
    const result = wasmModule.AddSquares(3, 4);
    setText(`addsq(3,4) := ${result}`);

    if (canvasRef.current === null) {
      return
    }

    const sceneId = wasmModule.miroStartNewScene();
    console.log(`sceneId = ${sceneId}`);

    wasmModule.miroFillCurrentScene(sceneId);

    const ctx = canvasRef.current.getContext("2d") as CanvasRenderingContext2D;
    console.log(ctx);
    ctx.fillStyle = "red";
    ctx.fillRect(5, 5, 50, 70);
    const setOk = wasmModule.miroApplySceneToCanvas(sceneId, ctx);
    console.log(setOk);
  };

  return (
    <>
      <div>
        <button onClick={() => onClickBtn()}>Test WASM method</button>
        <br/>
        <div>{text}</div>
        <br/>
        <CanvasPanel canvasRef={canvasRef}></CanvasPanel>
      </div>
    </>
  )
}

export default App
