
public class MaiorTopo{
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
        public void MaiorTopo()
    {
        Pilha p = new Pilha();
        p.topo = null;
        
        while(this.topo !=null)
        {
            int valor = this.pop();
            if(p.topo == null)
            {
                p.push(valor);
            }
            else{
                while(p.topo != null && valor > p.peek())
                {this.push(p.pop());}
                p.push(valor);
                }
        }
        while(p.topo != null)
        {
            this.push(p.pop());
        }

        }
    }
    public static void main(String[] args) {
    Pilha Origem = new Pilha();
    Origem.push(10);
    Origem.push(5);
    Origem.push(20);
    Origem.push(15); // Topo = 15
    
    System.out.println("Topo antes: " + Origem.peek()); // Mostra 15
    Origem.MaiorTopo();
    System.out.println("Topo depois: " + Origem.peek()); // (Depende da sua lógica)
}
}
    
