public class SomarTodos {
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
        Celula topo;
        public Pilha()
        {
            this.topo = null;
        }
        public int pop()
        {
            if(this.topo == null)throw new IllegalArgumentException("Pilha Vazia");
            else
            {
                int valor = this.topo.elemento;
                this.topo = this.topo.prox;
                return valor;
            }
        }
        public void push(int elemento)
        {
            Celula novoNo = new Celula();
            novoNo.prox= this.topo;
            novoNo.elemento = elemento;
            this.topo = novoNo;
        }
        public int peek()
        {
            return this.topo.elemento;
        }
        public int SomarTudo()
        {
            Pilha p = new Pilha();
            if(this.topo == null){throw new IllegalArgumentException("Pilha vazia, nn e possivel somar");}
            else{
            int somatorio = 0;
                while(this.topo != null)
                {
                    int valor = this.pop();
                    somatorio += valor;
                    p.push(valor);
                }
                while(p.topo!=null)
                {
                    this.push(p.pop());
                }
                return somatorio;
            }
        }
    }
}
