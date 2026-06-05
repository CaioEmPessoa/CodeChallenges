import SidebarSection from "./SidebarSection"

function Sidebar() {
    return(
        <div>
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