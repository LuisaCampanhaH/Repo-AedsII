public class FIlacomPilhas 
{
    static class Celula{
        public int elemento;
        public Celula prox;
        public Celula()
        {
            this.elemento = 0;
            this.prox = null;
        }        
    }
    static class Pilha{
        public Celula topo;
        public Pilha()
        {
            this.topo = null;
        }
        public void push(int elemento)
        {
            Celula novoNo = new Celula();
            novoNo.elemento = elemento;
            novoNo.prox = this.topo;
            this.topo = novoNo;
        }
        public int pop()
        {
            if(this.topo == null)return -1;
            else
            {
                int valor = this.topo.elemento;
                this.topo = this.topo.prox;
                return valor;
            }
        }
        public int peek()
        {
            if(this.topo == null)return-1;
            else
            {
                return this.topo.elemento;
            }
        }
        public  boolean isVazia()
        {
            if(this.topo == null)return true;
            return false;
        }
    }
    static class Fila{
    // (Assumindo que PilhaEncadeada com .empilhar, .desempilhar e .isVazia() existe)
    
    public Pilha pEntrada;
    public Pilha pSaida;

    public Fila() {
        this.pEntrada = new Pilha();
        this.pSaida = new Pilha();
    }

    /**
     * Adiciona um elemento ao FIM da fila.
     */
    public void enfileirar(int x) {
        // Sempre empilha na pEntrada.
        pEntrada.push(x);
    }

    /**
     * Remove e retorna o elemento do INÍCIO da fila.
     */
    public int desenfileirar() throws Exception {
        
        // 1. Se a pSaida NÃO estiver vazia, o elemento
        //    correto (mais antigo) já está no topo dela.
        if (!pSaida.isVazia()) {
            return pSaida.pop();
        }
        
        // 2. Se a pSaida ESTÁ vazia, devemos transferir
        //    tudo da pEntrada para a pSaida.
        while (!pEntrada.isVazia()) {
            pSaida.push(pEntrada.pop());
        }
        
        // 3. Agora, se a pSaida AINDA estiver vazia (porque
        //    a pEntrada também estava), a fila está vazia.
        if (pSaida.isVazia()) {
            throw new Exception("A fila está vazia!");
        }
        
        // 4. Se chegamos aqui, a transferência foi feita,
        //    e podemos desempilhar da pSaida.
        return pSaida.pop();
    }
}
}

