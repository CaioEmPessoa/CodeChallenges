
import React, { type ReactNode } from 'react';

import styles from "./NumberedList.module.css"

interface NumberedListProps {
    title: string;
    itens: ReactNode[];
}

function NumberedList({title, itens}: NumberedListProps) {

    const liItens = itens.map(item =>
        <li className={styles.listItem}>{item}</li>
    );

    return(
        <div className={styles.container}>
            <h2 className={styles.title}>{title}</h2>
            <ol className={styles.orderedList}>
                {liItens}
            </ol>
        </div>
    );
}

export default NumberedList