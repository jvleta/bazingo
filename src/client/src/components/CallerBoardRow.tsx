import React from "react";

import CallerBoardCell from "./CallerBoardCell";

type Props = {
  letter: string;
  start: number;
  stop: number;
};

const CallerBoardRow: React.FC<Props> = ({ letter, start, stop }) => {
  let numbers: Array<number> = Array.from(
    { length: stop - start + 1 },
    (v, k) => k + 1
  );
  console.log(numbers);
  const numericalCells = numbers.map((x) => {
    return <CallerBoardCell label={x.toString()} />;
  });
  console.log(numericalCells);
  const cells: Array<any> = [];
  for (let i = start; i <= stop; i++) {
    cells.push(<CallerBoardCell label={i.toString()} />);
  }
  return (
    <>
      <tr>
        <CallerBoardCell label={letter} /> {cells}
      </tr>
    </>
  );
};

export default CallerBoardRow;
