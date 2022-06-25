import React from 'react';
import styles from "./CallerBoardCell.module.css";

type Props = {
    label: string;
};

const CallerBoardCell: React.FC<Props> = (props: any) => {
  return <td className={styles.cell}>{props.label}</td>;
};

export default CallerBoardCell;