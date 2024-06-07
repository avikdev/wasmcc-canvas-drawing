import { memo } from "react";


interface CanvasPanelProps {
  canvasRef: React.RefObject<HTMLCanvasElement>,
}

/*
function CanvasPanel({canvasRef}: CanvasPanelProps): JSX.Element {
  //const canvasRef = useRef<HTMLCanvasElement>(null);

  return (
    <div>
      <canvas width={800} height={1200} ref={canvasRef} style={{backgroundColor: "#DDDDDD"}}></canvas>
    </div>
  );
}
*/

const CanvasPanel = memo(function CanvasPanel({canvasRef}: CanvasPanelProps): JSX.Element {
  //const canvasRef = useRef<HTMLCanvasElement>(null);

  return (
    <div>
      <canvas width={800} height={1200} ref={canvasRef} style={{backgroundColor: "#DDDDDD"}}></canvas>
    </div>
  );
},
// Do nont re-render.
() => true);

export default CanvasPanel;