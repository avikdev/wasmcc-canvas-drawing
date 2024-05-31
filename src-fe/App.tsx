import { useEffect, useState } from 'react';
import './App.css';
import WasmModule from "./wasm/starter-wasm.js";
import { useRef } from "react";
import CanvasPanel from './CanvasPanel.js';

let loadingStarted = false;

interface WasmInterface {
  addsq(a: number, b: number): number;
  SetCanvas2DContext(ctx: CanvasRenderingContext2D): boolean;
}

let wasmModule: WasmInterface | null = null;

function loadWasm() {
  if (loadingStarted) return;
  loadingStarted = true;
  window.setTimeout(async () => {
    const mod = await WasmModule();
    console.log(mod);
    wasmModule = mod as WasmInterface;
  }, 100);

}

function App() {
  const [text, setText] = useState("-");
  const canvasRef = useRef<HTMLCanvasElement>(null);

  useEffect(() => {
    loadWasm();
  }, []);

  const onClickBtn = () => {
    if (wasmModule === null) {
      return;
    }
    const result = wasmModule.addsq(3, 4);
    setText(`addsq(3,4) := ${result}`);

    console.log(canvasRef.current);
    if (canvasRef.current !== null) {
      const ctx = canvasRef.current.getContext("2d") as CanvasRenderingContext2D;
      console.log(ctx);

      ctx.fillStyle = "red";
      ctx.fillRect(5, 5, 50, 70);
      const setOk = wasmModule.SetCanvas2DContext(ctx);
      console.log(setOk);
    }
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
