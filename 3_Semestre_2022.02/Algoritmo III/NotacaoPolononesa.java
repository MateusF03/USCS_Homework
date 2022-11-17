/**
 * Código da aula de POO. Calculo com expressões simples de notação polonesa.
 *
 * @author Mateus Ferrari Julio
 * @version 1.0
 *
 */
public class Main {
    private static final HashSet<String> VALID_CHARS = new HashSet<>();

    static {
        VALID_CHARS.add("+");
        VALID_CHARS.add("-");
        VALID_CHARS.add("*");
        VALID_CHARS.add("/");
    }

    public static void main(String[] args) {
        String expression = "3 10 5 + *";
        varrer(expression);
    }

    private static void varrer(String exp) {
        Pilha p = new Pilha(1000);
        String[] s = exp.trim().split("\\s+");
        for (String val : s) {
            if (isInteger(val)) {
                p.empilha(Integer.parseInt(val));
            } else if (VALID_CHARS.contains(val)) {
                int a = p.desempilha();
                int b = p.desempilha();
                int resultado = 0;
                switch (val) {
                    case "+":
                        resultado = a + b;
                        break;
                    case "-":
                        resultado = a - b;
                        break;
                    case "*":
                        resultado = a * b;
                        break;
                    case "/":
                        resultado = a / b;
                        break;
                }
                p.empilha(resultado);
            }
        }
        System.out.println(p.desempilha());
    }

    private static boolean isInteger(String s) {
        return isInteger(s,10);
    }

    private static boolean isInteger(String s, int radix) {
        if(s.isEmpty()) return false;
        for(int i = 0; i < s.length(); i++) {
            if(i == 0 && s.charAt(i) == '-') {
                if(s.length() == 1) return false;
                else continue;
            }
            if(Character.digit(s.charAt(i),radix) < 0) return false;
        }
        return true;
    }
}
