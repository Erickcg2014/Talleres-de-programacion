public class Empleado {
    private String nombre;
    private int edad;
    private double salario;

    public Empleado(String nombre, int edad, double salario) {
        this.nombre = nombre;
        this.edad = edad;
        this.salario = salario;
    }

    public String getNombre() {
        return nombre;
    }

    public int getEdad() {
        return edad;
    }

    public double getSalario() {
        return salario;
    }

    public void aumentarSalario(double porcentaje) {
        double aumento = salario * porcentaje / 100;
        salario += aumento;
    }

    public void imprimirInformacion() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Edad: " + edad);
        System.out.println("Salario: $" + salario);
    }
}

public class Main {
    public static void main(String[] args) {
        Empleado empleado1 = new Empleado("Juan", 30, 2500.0);
        Empleado empleado2 = new Empleado("María", 35, 3000.0);

        empleado1.imprimirInformacion();
        empleado2.imprimirInformacion();

        empleado1.aumentarSalario(10);
        empleado2.aumentarSalario(8);

        System.out.println("\nDespués del aumento de salario:");

        empleado1.imprimirInformacion();
        empleado2.imprimirInformacion();
    }
}
