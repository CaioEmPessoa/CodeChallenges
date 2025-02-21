public class atv4 {

    public int classeAdicional(){
        return 200;
    }

    public static void main(String[] args) {
        atv4 acessoClasse = new atv4();

        if (acessoClasse.classeAdicional() == 200)  {
            System.out.println("Aceso válido!");
        } else {
            System.out.println("Acesso Inválido!");
        }

    }
}
