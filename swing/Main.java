/**
 * Classe principale qui permet de lancer la connexion avec le serveur et 
 * d'instancier une fenêtre de contrôle
 */
public class Main {
		static final String DEFAULT_HOST = "localhost";
		static final int DEFAULT_PORT = 3331;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Code pour afficher la fenêtre de l'étape 1
		//Window ex = new Window();
        //ex.display();
		
		Client client = null ;
		
		try {
			client = new Client(DEFAULT_HOST, DEFAULT_PORT);
		}
		catch (Exception e) {
			System.err.println("Erreur de connexion");
			System.exit(1);
		}
		
		ControlWindow ex = new ControlWindow("Fenetre de Elie", client);
		ex.display();
		
		
	}

}
