import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Contacto {
    private String nombre;
    private String telefono;
    private String email;

    public Contacto(String nombre, String telefono, String email) {
        this.nombre = nombre;
        this.telefono = telefono;
        this.email = email;
    }

    public String getNombre() {
        return nombre;
    }

    public String getTelefono() {
        return telefono;
    }

    public String getEmail() {
        return email;
    }

    public void imprimirInformacion() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Teléfono: " + telefono);
        System.out.println("Email: " + email);
    }
}

public class GestionContactos {
    public static void main(String[] args) {
        List<Contacto> contactos = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);
        boolean continuar = true;

        while (continuar) {
            System.out.println("=== Gestión de Contactos ===");
            System.out.println("1. Agregar contacto");
            System.out.println("2. Mostrar contactos");
            System.out.println("3. Salir");
            System.out.print("Seleccione una opción: ");
            int opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    scanner.nextLine(); // Limpiar el búfer del scanner

                    System.out.print("Ingrese el nombre del contacto: ");
                    String nombre = scanner.nextLine();
                    System.out.print("Ingrese el teléfono del contacto: ");
                    String telefono = scanner.nextLine();
                    System.out.print("Ingrese el email del contacto: ");
                    String email = scanner.nextLine();

                    Contacto nuevoContacto = new Contacto(nombre, telefono, email);
                    contactos.add(nuevoContacto);

                    System.out.println("Contacto agregado correctamente.");
                    break;
                case 2:
                    System.out.println("=== Lista de Contactos ===");
                    for (Contacto contacto : contactos) {
                        contacto.imprimirInformacion();
                        System.out.println("--------------------------");
                    }
                    break;
                case 3:
                    continuar = false;
                    System.out.println("Saliendo del programa...");
                    break;
                default:
                    System.out.println("Opción inválida. Por favor, seleccione nuevamente.");
                    break;
            }

            System.out.println();
        }

        scanner.close();
    }
}
