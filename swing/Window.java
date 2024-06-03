import java.awt.EventQueue;
import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.Dimension;

/**
 * Cette classe permet de créer la fenêtre de l'étape 1 à l'aide de la stratégie numéro 2.
 * En effet, elle implémente un ActionListener permettant de spécifier le comportement des boutons.
 * Comme demandé, la fenêtre est composée d'une zone de texte et de 3 boutons.
 * 
 * @author Anna van Elst
 * 
 */

public class Window extends JFrame implements ActionListener {
	
	private static final long serialVersionUID = 1L;
	private static JTextArea textArea ;
	private JPanel container = new JPanel();
	private JButton searchButton ;
	private JButton playButton ;
	private JButton closeButton ;
	
	
	/**
	 * Ce constructeur permet de créer une classe Window qui dérive d'un JFrame. 
	 * Il fait appelle à la méthode initUI.
	 */
	
	public Window() {

        initUI();
    }
	
	/**
	 * Ce méthode permet d'intialiser la classe Window (notre fenêtre de contrôle) avec les bons paramètres. 
	 * Elle initialise une JFrame avec le nom "Fenêtre de contrôle" et une taille de 600x500.
	 */
	

    private void initUI() {
        
        setTitle("Fenetre de controle"); // donne un nom à la JFrame
        setSize(600, 500); //définit la taille de la fenêtre
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE); // ferme la fenêtre quand on clique sur la croix
    }
    
    /**
	 * Ce méthode permet d'affficher les différents composants de la fenêtre : 
	 * une zone de texte au centre et 3 boutons en bas (Chercher, Jouer, Fermer).
	 * Le bouton chercher permet d'afficher "Chercher..." sur la zone de texte
	 * Le bouton jouer permet d'afficher "Jouer..." sur la zone de texte.
	 * Le bouton fermer permet de fermer la fenêtre.
	 */
    
    public void display() {
    	
    	textArea = new JTextArea(30, 30); //création d'une zone de texte
    	searchButton = new JButton("Chercher"); //bouton chercher
    	playButton = new JButton("Jouer"); //bouton jouer
    	closeButton = new JButton("Fermer"); //bouton fermer
   
    	
		//on met le textArea dans un scrollpane pour avoir un ascenseur
		JScrollPane scrollPane = new JScrollPane(textArea);
		
		//création d'une barre d'outils pour mettre les boutons
		container.setLayout(new BorderLayout());
		container.add(searchButton,BorderLayout.CENTER);
		container.add(playButton,BorderLayout.WEST);
		container.add(closeButton,BorderLayout.EAST);
		
		//définition de la taille des boutons
		searchButton.setPreferredSize(new Dimension(120, 30));
		playButton.setPreferredSize(new Dimension(120, 30));
		closeButton.setPreferredSize(new Dimension(120, 30));

		//définition de la structure de la fenêtre
		add(container, BorderLayout.SOUTH);
		add(scrollPane, BorderLayout.CENTER);
		//add(textArea, BorderLayout.CENTER); (avant ajout d'un scrollPane
		
		searchButton.addActionListener(this);
	    playButton.addActionListener(this);
	    closeButton.addActionListener(this);

		pack(); //calcule la disposition spatiale
		setVisible(true); //rend l'interface visible
	}
    
    /**
	 * Ce méthode de l'interface ActionListener permet de spécifier la comportement de chaque bouton.
	 */
    
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
		if(arg0.getSource() == searchButton)
			//affiche "chercher" quand on appuie sur le bouton
			textArea.append("Chercher... \n"); 

		if(arg0.getSource() == playButton)
			//affiche "jouer" quand on appuie sur le bouton
			textArea.append("Jouer... \n");
		
		if(arg0.getSource() == closeButton)
			//ferme la fenêtre quand on appuie sur le bouton
			System.exit(0);
		
	}
   
    

    
}
