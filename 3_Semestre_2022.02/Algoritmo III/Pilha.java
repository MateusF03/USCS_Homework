public class Pilha {
    private int topo = -1;
    
    private final int capacidade;
    private final int[] dados;
    
    public Pilha(int capacidade) {
        this.capacidade = capacidade;
        this.dados = new int[capacidade];
    }
    
    public void empilha(int valor) {
        if (cheio()) {
            throw new IllegalArgumentException("A pilha está cheia");
        }
        dados[++topo] = valor;
    }
    
    public boolean cheio() {
        return (topo + 1 == capacidade);
    }
    
    public void imprime() {
        for (int valor: dados) {
            System.out.println(valor);
        }
    }
    
    public void imprimeAoContrario() {
        for (int i = topo; i >= 0; i--) {
            System.out.println(dados[i]);
        }
    }
}
