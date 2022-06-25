import "./App.css";
import CallerBoardRow from "./components/CallerBoardRow";
function App() {
  return (
    <div className="App">
      <table>
        <CallerBoardRow letter={"B"} start={1} stop={15} />
        <CallerBoardRow letter={"I"} start={16} stop={30} />
        <CallerBoardRow letter={"N"} start={31} stop={45} />
        <CallerBoardRow letter={"G"} start={46} stop={60} />
        <CallerBoardRow letter={"O"} start={61} stop={75} />
      </table>
    </div>
  );
}

export default App;
