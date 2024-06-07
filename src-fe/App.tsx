import { useEffect, useState } from 'react';
import './App.css';
import { useRef } from "react";
import CanvasPanel from './CanvasPanel.js';
import WasmSetup, { WasmInterface } from './WasmSetup.js';
import PlayCoordinator from './PlayCoordinator.js';

function App() {
  const [text, setText] = useState("-");
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const wasmModuleRef = useRef<WasmInterface | null>(null);

  useEffect(() => {
    if (wasmModuleRef.current) return;
    const timeoutId = globalThis.setTimeout(async () => {
      wasmModuleRef.current = await WasmSetup.awaitModuleLoaded();
    }, 0);
    return () => { globalThis.clearTimeout(timeoutId) };
  }, []);

  const onClickBtn = () => {
    const wasm = wasmModuleRef.current;
    if (!wasm) {
      return;
    }
    const result = wasm.AddSquares(3, 4);
    setText(`addsq(3,4) := ${result}`);

    if (canvasRef.current === null) {
      return;
    }

    const pc = new PlayCoordinator(wasm);
    pc.testPlayWithCanvas(canvasRef.current);
  };

  const onClickTestP5Btn = () => {
    console.log("Test something !!");
  };

  return (
    <>
      <div>
      <button onClick={() => onClickBtn()}>Test WASM method</button>
      <button onClick={() => onClickTestP5Btn()}>Test P5</button>
        <br/>
        <div>{text}</div>
        <br/>
        <CanvasPanel canvasRef={canvasRef}></CanvasPanel>
      </div>
    </>
  )
}

export default App
