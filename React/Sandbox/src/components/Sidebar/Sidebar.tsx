import React, {useState} from "react"

import SidebarSection from "./SidebarSection"
import styles from "./Sidebar.module.css"
import Button from "./Button";

function Sidebar() {
    const [sidebarTitle, setSidebarTitle] = useState("Website");

    return(
        <div className={styles.sidebar}>
            <h1>{sidebarTitle}</h1>
            <Button text="Teste" setSidebarTitle={setSidebarTitle}/>
            <SidebarSection title="Meus sites favs:" urls={[
                    {text:"git.gay", href: "https://git.gay"},
                    {text:"minecraft", href: "https://minecraft.com"},
                    {text:"google", href: "https://google.com"}
                ]}  />
            <SidebarSection title="EU ODEIO ESSES SITES:" urls={[
                    {text:"git.gay", href: "https://git.gay"},
                    {text:"minecraft", href: "https://minecraft.com"},
                    {text:"google", href: "https://google.com"}
                ]}  />
            <SidebarSection title="Nem ligo I-I:" bottomBorder={false} urls={[
                    {text:"git.gay", href: "https://git.gay"},
                    {text:"minecraft", href: "https://minecraft.com"},
                    {text:"google", href: "https://google.com"}
                ]}  />
        </div>
    )
}

export default Sidebar