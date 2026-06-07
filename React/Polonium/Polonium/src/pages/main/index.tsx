
import React, {useState} from 'react';

import styles from './index';

import TodoList from '../../components/todo-list/todo-list';
import { type todoListData } from '../../components/todo-list/todo-list';

function Index() {

    const [todoLists, setTodoLists] = useState<Array<todoListData>>([
        {
            "name":"Teste",
            "itens":[]
        }
    ])

    let ex = todoLists[0]

    return (
        <>
        <h1>SacoBolas</h1>
        <TodoList {...ex} />
        </>
    );
}

export default Index