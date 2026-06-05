
interface Components{
    href: string;
    text: string;
}

function SidebarSection(title:string, components:Components){
    const title_sz:Number = title.length

    return(
        <div>
            <title>{title} - {title_sz.toString()}</title>
            <a href={components.href}>{components.text}</a>
        </div>
    )

}

export default SidebarSection