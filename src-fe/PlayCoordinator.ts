import { v4 as uuidv4 } from 'uuid';
import { WasmInterface } from "./WasmSetup";
import miroProject from './draftp5';



class PlayCoordinator {
  readonly wasm: WasmInterface;
  sceneId: string = "";

  constructor(wasm: WasmInterface) {
    this.wasm = wasm;
  }

  public testPlayWithCanvas(canvas: HTMLCanvasElement) {
    const id = this.sceneId = uuidv4();
    this.wasm.miroStartNewScene(id);
    //this.wasm.miroFillCurrentScene(id);
    console.log(miroProject);
    this.wasm.miroLoadCurrentScene(id, miroProject);

    const context = canvas.getContext("2d") as CanvasRenderingContext2D;
    this.wasm.miroApplySceneToCanvas(id, context);
  }


}

export default PlayCoordinator;