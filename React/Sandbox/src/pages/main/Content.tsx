import NumberedList from "../../components/NumberedList/NumberedList"
import Card from "../../components/Card/Card"

import harmony from "../../assets/harmony.gif"

function Content() {
    return(
        <div className="content">
            <h2>Conteúdo do meu Website</h2>
            <NumberedList title="Primeiro" itens={["test", "test", <br/>]} />
            <Card title="Meu Github" url="https://github.com/caioempessoa" picture={harmony} />
        </div>
    )
}

export default Content