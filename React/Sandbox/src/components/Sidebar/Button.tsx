import type React from "react";

interface ButtonProps {
    text:string;
    setSidebarTitle:Function
}

function Button({text, setSidebarTitle}:ButtonProps) {

    const updateSidebar = (e:React.MouseEvent<HTMLButtonElement>) => {
        setSidebarTitle((e.target as HTMLButtonElement).innerText)
    }

    return(
        <button onClick={updateSidebar}>{text}</button>
    );
}

export default Button