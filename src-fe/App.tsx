import { useEffect, useState } from 'react';
import './App.css';
import WasmModule from "./wasm/starter-wasm.js";

let loadingStarted = false;

interface WasmInterface {
  _addsq(a: number, b: number): number;
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

  useEffect(() => {
    loadWasm();
  }, []);

  const onClickBtn = () => {
    if (wasmModule === null) {
      return;
    }
    const result = wasmModule._addsq(3, 4);
    setText(`addsq(3,4) := ${result}`);
  };

  return (
    <>
      <div>
        <button onClick={() => onClickBtn()}>Test WASM method</button>
        <br/>
        <div>{text}</div>
      </div>
    </>
  )
}

export default App
