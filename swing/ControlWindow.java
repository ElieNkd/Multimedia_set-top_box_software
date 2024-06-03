import java.awt.EventQueue;
import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.*;

/**
* Cette classe permet de créer la fenêtre de l'étape 2 à l'aide de la stratégie utilisant des actions.
* En effet, elle contient des sous-classes de AbstractAction
* Comme demandé, la fenêtre est composée d'une zone de texte et de 3 boutons.
* 
* @author Anna van Elst
* 
*/

public class ControlWindow extends JFrame {
	
	private static final long serialVersionUID = 1L;
	private static JTextArea textArea ;
	private JButton searchButton ;
	private JButton playButton ;
	private JButton displayButton ;
	private JButton closeButton ;
	private JScrollPane scrollPane;
	private JToolBar bar ;
	private JMenuBar menuBar ;
	private JMenu menu ; 
	private Client client;
	private JDialog dialog ;
	private JTextField textField ;
	
	/**
	 * constructeur de la classe ControlWindow
	 * @param name nom de la fenêtre
	 * @param client 
	 */
	public ControlWindow(String name, Client client) {
        initUI(name);
        this.client = client;
    }
	
	/**
	 * méthode qui spécifie les paramètres de la JFrame
	 * @param name nom de la fenêtre
	 */
    private void initUI(String name) {
        
        setTitle(name); // donne un nom à la JFrame
        setSize(600, 500); //définit la taille de la fenêtre
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE); // ferme la fenêtre quand on clique sur la croix
    }
    
    /**
     * méthode qui permet d'afficher le contenu de la fenêtre
     */
    public void display() {
    	    	
    	//création d'une zone de texte
    	textArea = new JTextArea(50, 50); 
    	textArea.append(" Instructions : \n \n");
    	textArea.append(" Pour chercher un fichier, entrez le nom dans le barre de recherche puis cliquez sur le bouton chercher un fichier \n");
    	textArea.append("	-> exemple de noms possibles : universe, supernova \n \n");
    	textArea.append(" Pour afficher un fichier, entrez le nom dans la barre de recherche puis cliquez sur le bouton Afficher un fichier \n");
    	textArea.append("	-> exemple de noms possibles : universe, supernova \n \n");
    	textArea.append(" Pour afficher un groupe, entrez le nom dans le barre de recherche puis cliquez sur le bouton afficher un groupe \n");
    	textArea.append("	-> exemple de noms possibles : group \n \n");
    	textArea.append(" Pour quitter le fenêtre, cliquez sur le bouton fermer \n \n");
    	
    	//on met le textArea dans un scrollpane pour avoir un ascenseur
    	scrollPane = new JScrollPane(textArea);		
    	
    	//création des 3 boutons avec actions
    	SeAction seAction = new SeAction("Chercher un fichier");
		PAction pAction = new PAction("Afficher un fichier");
		DAction dAction = new DAction("Afficher un groupe");
		QAction qAction = new QAction("Fermer");
	
		//on spécifie les caractéristiques des boutons à l'aide des actions
    	searchButton = new JButton(seAction);
		playButton = new JButton(pAction);
		displayButton = new JButton(dAction);
		closeButton = new JButton(qAction);
		
		//on définit la taille de chaque bouton
		searchButton.setPreferredSize(new Dimension(150, 30));
		playButton.setPreferredSize(new Dimension(150, 30));
		displayButton.setPreferredSize(new Dimension(150, 30));
		closeButton.setPreferredSize(new Dimension(150, 30));
		
		//création d'une barre de menu
		menuBar = new JMenuBar();
		
		//création d'un menu déroulant 
		menu = new JMenu("Menu");
		menu.add(new JMenuItem(seAction));
		menu.add(new JMenuItem(pAction));
		menu.add(new JMenuItem(dAction));
		menu.add(new JMenuItem(qAction));
    	
		//création d'une barre d'outils pour mettre les boutons
		bar = new JToolBar();
		bar.add(searchButton);
		bar.add(playButton);
		bar.add(displayButton);
		bar.add(closeButton);
		
		//création d'une zone de texte pour entrer le nom du fichier
		textField = new JTextField("Veuilllez entrer le nom du fichier");
		textField.setColumns(30);
		bar.add(textField);
		
		//on ajoute le menu déroulant à la barre de menus
		menuBar.add(menu);
		
		//on ajoute la barre de menus à la fenêtre
		setJMenuBar(menuBar);
		
		
		//on place la barre d'outil en haut de la fenêtre
		add(bar, BorderLayout.NORTH);
		
		//on place la zone de texte en bas
		add(scrollPane, BorderLayout.SOUTH);		
		
		pack(); //calcule la disposition spatiale
		setVisible(true); //rend l'interface visible
	}
   
    /**
     * classe héritée de AbstractAction qui permet de spécifier le comportement du bouton Chercher
     */
    private class SeAction extends AbstractAction{
    	private static final long serialVersionUID = 1L;
    	
    	public SeAction(String name) {
    		super(name);
    	}
    	
    	@Override 
    	public void actionPerformed(ActionEvent e) {
    		//on ajoute le string jouer dans la zone de texte
    		textArea.append("Chercher... \n");
    		String request = client.send("msearch "+ textField.getText()); //on envoie une requête au serveur
    		textArea.append(request);
    	}
    	
    }
    
    /**
     * classe héritée de AbstractAction qui permet de spécifier le comportement du bouton Chercher
     */
    private class PAction extends AbstractAction{
    	private static final long serialVersionUID = 1L;
    	
    	public PAction(String name) {
    		super(name);
    	}
    	
    	@Override 
    	public void actionPerformed(ActionEvent e) {
    		//on ajoute le string jouer dans la zone de texte
    		textArea.append("Jouer... \n");  
    		String request = client.send("play " + textField.getText());
			textArea.append(request);
    		
    		
    	}
    	
    }
    
    /**
     * classe héritée de AbstractAction qui permet de spécifier le comportement du bouton Afficher
     */
    private class DAction extends AbstractAction{
    	private static final long serialVersionUID = 1L;
    	
    	public DAction(String name) {
    		super(name);
    	}
    	
    	@Override 
    	public void actionPerformed(ActionEvent e) {
    		//on ajoute le string jouer dans la zone de texte
    		textArea.append("Afficher... \n");  
    		String request = client.send("gsearch " + textField.getText()); //on envoie une requête au serveur
			textArea.append(request);
    		
    		
    	}
    	
    }
    
    /**
     * classe héritée de AbstractAction qui permet de spécifier le comportement du bouton quitter
     */
    private class QAction extends AbstractAction{
    	private static final long serialVersionUID = 1L;
    	
    	public QAction(String name) {
    		super(name);
    	}
    	
    	@Override 
    	public void actionPerformed(ActionEvent e) {
    		//utilisation de la méthode exit de system pour quitter la fenêtre
    		System.exit(0);
    		String request = client.send("quit"); //permet de clore la connexion avec le serveur
    		textArea.append(request);
    	}
    	
    }

    
}
