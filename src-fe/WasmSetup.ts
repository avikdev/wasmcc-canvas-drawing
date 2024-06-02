import { v4 as uuidv4 } from 'uuid';
import WasmModule from './wasm/starter-wasm.js';

interface WasmInterface {
  AddSquares(a: number, b: number): number;
  miroStartNewScene(): string;
  miroFillCurrentScene(sceneId: string): void;
  miroApplySceneToCanvas(ceneId: string, context: CanvasRenderingContext2D): boolean;
}

const WasmSetup = (function WasmSetup() {
  // Create a global portal object with some utility method which can be
  // reused from inside the C++ realm.
  (globalThis as any).portalToCC = makePortalObjectForCpp();

  let module: WasmInterface | null = null;
  let moduleError: any = null;

  // Initiate module load.
  window.setTimeout(async () => {
    try {
      module = await WasmModule();
    } catch (e: any) {
      moduleError = e;
    }
  }, 0);

  return {
    // Waits until the wasm module is loaded.
    async awaitModuleLoaded() : Promise<WasmInterface> {
      return new Promise((resolve, reject) => {
        const resolvedOrRejectedFn = () => {
          if (module !== null) {
            resolve(module);
          } else if (moduleError !== null) {
            reject(moduleError);
          } else {
            return false;
          }
          return true;
        };
        if (resolvedOrRejectedFn()) return;
        const interval = globalThis.setInterval(() => {
          resolvedOrRejectedFn() && globalThis.clearInterval(interval);
        }, 10);  // Poll every 10 msec.
      });
    },
  };
})();

function makePortalObjectForCpp() {
  return {
    uuid: function() : string {
      return uuidv4();
    },
    atob: function(arg: string) : string {
      return window.atob(arg);
    },
  };
}

export default WasmSetup;
export { type WasmInterface };