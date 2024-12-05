public class Banco {

    private String numero;
    private String nome;
    private float saldo;

    public void debitar(float valor) {
        saldo = saldo - valor;
    }

    public void creditar(float valor) {
        saldo = saldo + valor;
    }

    public float getSaldo() {
        return saldo;
    }

    public String getNome() {
        return nome;
    }

    public String getNumero() {
        return numero;
    }

    public Banco(String numeroInicial, String nome, float saldoInicial) {
        numero = numeroInicial;
        saldo = saldoInicial;
    }
    
    public static void main(String[] args) {

        Banco contaGab = new Banco("23456-78", "Gabriel", 1000);
        Banco contaDoc = new Banco("666-13", "Mudroc", 66666);

        System.out.println("----------  CONTA GABRIEL  ----------");
        System.out.println("Saldo atual é de: " + contaGab.getSaldo());
        System.out.println(contaGab.getSaldo());

        System.out.println("Debitando R$100...");
        contaGab.debitar(100);

        System.out.println("Total da conta:" + contaGab.getSaldo());

        System.out.println("\n\n");

        System.out.println("----------  CONTA MURODC  ----------");

        final float valorCreditar = 9999;
        System.out.println("INFORMACOES DA CONTA:");
        System.out.println("NUMERO DA CONTA:" + contaDoc.getNumero());
        System.out.println("NOME DA CONTA:" + contaDoc.getNome());
        System.out.println("SALDO ATUAL: R$" + contaDoc.getSaldo());

        System.out.println("\n-----------------------\n");

        System.out.println("Creditando conta no valor de " + valorCreditar + " por que ele merece ;)");
        contaDoc.creditar(valorCreditar);

        System.out.println("SALDO NOVO: R$" + contaDoc.getSaldo());
        
    }
}


