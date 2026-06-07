
import styles from "./SidebarSection.module.css"

interface SidebarUrls{
    href: string;
    text: string;
}

interface SidebarSectionProps{
    title         : string;
    urls          : Array<SidebarUrls>
    bottomBorder ?: Boolean
}


function SidebarSection({title, urls, bottomBorder=true}:SidebarSectionProps){

    const sidebarUrls = urls.map(url =>
        <a href={url.href} className={styles.url} >{url.text}</a>
    );

    return(
        <div>
            <h3 className={styles.title} >{title}</h3>
            {sidebarUrls}
            {bottomBorder ? <hr/> : ""}
        </div>
    )

}

export default SidebarSection