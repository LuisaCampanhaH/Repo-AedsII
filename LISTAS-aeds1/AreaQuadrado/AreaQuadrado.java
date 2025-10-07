import java.util.*;

// FUNÇÃO JAVA PARA CALCULAR A AREA DE UM QUADRADO QUALQUER//
// FORMULA PARA O CALCULO: Area = lado x lado; //
class AreaQuadrado
{
    //Leitura e formula da função//
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        // Tratamento de exeção para lidar com numeros negativos//
        try 
        {
            System.out.println("Digite o lado do quadrado: ");
            double lado = sc.nextDouble();
            if(lado < 0)
            {
                throw new IllegalArgumentException("Voce deve digitar um numero valido");
            }
            double resultado;
            resultado = lado * lado;
            System.out.println("A area do quadrado e: " + resultado);
        }
        catch (IllegalArgumentException e) {
            // e.getMessage() recupera a mensagem que definimos no "throw".
            System.out.println("ERRO: " + e.getMessage());
        } 
    
    }
}