public class getMin {
static class Celula {
    public int elemento;
    public Celula prox;
    public int menorAteaqui; 

    public Celula(int elemento) { 
        this.elemento = elemento;
        this.prox = null;
        this.menorAteaqui = 0; 
    }
}

static class Pilha {
    Celula topo;
    
    // O construtor com 'x' e a var 'menor' não são mais necessários
    public Pilha() {
        this.topo = null;
    }
    public void push(int elemento) {
        Celula novoNo = new Celula(elemento); 

        if (this.topo == null) {
            novoNo.menorAteaqui = elemento;
        } else {
            int minAntigo = this.topo.menorAteaqui;
            
            if (elemento < minAntigo) { 
                novoNo.menorAteaqui = elemento;
            } else {
                novoNo.menorAteaqui = minAntigo;
            }
        }
        
        novoNo.prox = this.topo;
        this.topo = novoNo;
    }
    public int getMin() throws Exception {
        if (this.topo == null) {
            throw new Exception("Pilha Vazia!");
        }
        
        return this.topo.menorAteaqui;
    }
}
}