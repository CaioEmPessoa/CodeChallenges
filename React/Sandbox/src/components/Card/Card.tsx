
import styles from './Card.module.css'

interface CardProps {
    title: string;
    url: string;
    picture: string
}

function Card({title, url, picture}:CardProps) {
    return(
        <div className={styles.card}>
            <div className={styles.cardImgDiv}>
                <img src={picture} alt="" className={styles.cardImg} />
            </div>
            <div className={styles.cardContent}>
                <p className={styles.cardTitle}>{title}</p>
                <p className={styles.cardDescription}></p>
                <div className={styles.cardBottom}>
                    <hr className={styles.cardSeparator} />
                    <p className={styles.cardUrl}>{url}</p>
                </div>
            </div>
        </div>
    );
}

export default Card