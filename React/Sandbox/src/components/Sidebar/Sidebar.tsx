import SidebarSection from "./SidebarSection"

function Sidebar() {
    return(
        <div>
            {SidebarSection("Titulo", {href: "https://git.gay", text:"git.gay"})}
            {SidebarSection("Titulo", {href: "https://git.gay", text:"google"})}
            {SidebarSection("Titulo", {href: "https://git.gay", text:"minecraft"})}
        </div>
    )
}

export default Sidebar