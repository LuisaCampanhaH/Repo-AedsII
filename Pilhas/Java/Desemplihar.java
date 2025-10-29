public class Desemplihar {
    static class Celula
    {
        public int elemento;
        public Celula proximo;
        public Celula()
        {
            this.elemento = 0;
            this.proximo = null;
        }
    }
    static class Pilha{
        public Celula topo;

        public Pilha()
        {
            this.topo = null;
        }

        public int pop()
        {
            if(this.topo == null)
            {
                throw new IllegalArgumentException ("Pilha Vazia");
            }
            else{
                int valor = this.topo.elemento;
                this.topo = this.topo.proximo;
                return valor;
            }
        }

    }
    public static void main(String[] args) {
        try {
            Pilha p = new Pilha();
            p.topo.elemento = 4;
            p.topo.elemento = 4;
            System.out.println(p.pop());
        } catch (Exception e) {System.out.println("Erro" + e.getMessage());}
    }
}
