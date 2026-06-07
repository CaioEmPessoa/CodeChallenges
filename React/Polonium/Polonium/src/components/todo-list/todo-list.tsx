
import React, {useState} from 'react';

// import './todoList.module.css'
import TodoItem from './todo-item';
import { type todoItemData } from './todo-item';

interface todoListData{
    "name" : string;
    "itens": Array<todoItemData>;
}

function TodoList(listInfo:todoListData) {

    const [todoList, setTodoList] = useState<todoListData>(listInfo)
    const [newItem, setNewItem] = useState<todoItemData>({"name": "", "finished": false})
    
    function removeTodoItem(index:number) {
        setTodoList({
            ...todoList, 
            "itens": todoList.itens.filter((_, i) => i !== index)
        })
    }
    function finishTodoItem(index:number) {}

    const listItens = todoList.itens.map((listItem, i) => 
        <TodoItem name={listItem.name} 
                  finished={listItem.finished}
                  removeTodoItem={removeTodoItem}
                  
                  index={i}
                  key={i}
        />
    )

    function handleNewItem(){
        setTodoList({...todoList, "itens": [
            ...todoList.itens, newItem
        ]})
        console.log(todoList)
    }

    return (
        <>
            <h1>{listInfo.name}</h1>
            {listItens}
            
            <br/>
            
            <input type="text" 
                   value={newItem.name || ""} 
                   onChange={(e) => {setNewItem({...newItem, "name": e.target.value})}} 
            />
            <button onClick={handleNewItem}>
                + New Item
            </button>
        </>
    );
}

export default TodoList
export { type todoListData }