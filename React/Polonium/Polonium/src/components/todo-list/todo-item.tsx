
import styles from './todoItem.module.css'
import React, {useState} from 'react';

interface todoItemData{
    "name":string;
    "finished":boolean;
    "index":number;

    "removeTodoItem":Function
}

function TodoItem({name, finished, index, removeTodoItem}:todoItemData) {

    return (
        <p className={
            `${styles.todoItem} 
             ${finished && styles.todoItemFinished}`
            } 
            onClick={removeTodoItem(index)}
        >
            {name}
            </p>
    );
}

export default TodoItem
export { type todoItemData }