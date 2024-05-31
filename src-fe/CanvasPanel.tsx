
interface CanvasPanelProps {
  canvasRef: React.RefObject<HTMLCanvasElement>,
}

function CanvasPanel({canvasRef}: CanvasPanelProps): JSX.Element {
  //const canvasRef = useRef<HTMLCanvasElement>(null);

  return (
    <div>
      <canvas width={400} height={600} ref={canvasRef} style={{backgroundColor: "#DDDDDD"}}></canvas>
    </div>
  );
}

export default CanvasPanel;