import NumberedList from "../../components/NumberedList/NumberedList"

function Content() {
    return(
        <div className="content">
            <h2>Conteúdo do meu Website</h2>
            <NumberedList title="Primeiro" itens={["test", "test", <br/>]} />
        </div>
    )
}

export default Content