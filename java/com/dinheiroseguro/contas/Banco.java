package com.dinheiroseguro.contas;

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

        Banco contas[] = new Banco[1000];

        contas[0] = new Banco("23456-78", "Gabriel", 1000);
        contas[666] = new Banco("666-13", "Mudroc", 66666);

        UtilitarioContas uc = new UtilitarioContas();
        
        

        System.out.println("----------  CONTA GABRIEL  ----------");
        System.out.println("Saldo atual é de: " + contas[0].getSaldo());
        System.out.println(contas[0].getSaldo());

        System.out.println("Debitando R$100...");
        contas[0].debitar(100);

        System.out.println("Total da conta:" + contas[0].getSaldo());

        System.out.println("\n\n");

        System.out.println("----------  CONTA MURODC  ----------");

        final float valorCreditar = 9999;
        System.out.println("INFORMACOES DA CONTA:");
        System.out.println("NUMERO DA CONTA:" + contas[666].getNumero());
        System.out.println("NOME DA CONTA:" + contas[666].getNome());
        System.out.println("SALDO ATUAL: R$" + contas[666].getSaldo());

        System.out.println("\n-----------------------\n");

        System.out.println("Creditando conta no valor de " + valorCreditar + " por que ele merece ;)");
        contas[666].creditar(valorCreditar);

        System.out.println("SALDO NOVO: R$" + contas[666].getSaldo());
        
    }
}


