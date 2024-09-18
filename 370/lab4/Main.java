import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

public class Main {
  public static void main(String[] args) {
    JFrame frame = new JFrame("Cards");
    frame.setSize(1000, 600);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JPanel panel = new JPanel();
    panel.setLayout(new GridLayout(4, 13));
    panel.setBackground(new Color(50, 180, 50));

    addCards(panel);

    JPanel buttonPanel = new JPanel();
    JButton button = new JButton("Shuffle");
    ActionListener buttonListener = new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        panel.removeAll();
        addCards(panel);
        panel.revalidate();
        panel.repaint();
      }
    };
    button.addActionListener(buttonListener);
    buttonPanel.add(button);

    frame.add(panel, BorderLayout.CENTER);
    frame.add(buttonPanel, BorderLayout.SOUTH);
    frame.setVisible(true);
  }

  public static void addCards(JPanel panel) {
    File dir = new File("cards");
    File[] cards = dir.listFiles();
    List<File> list = Arrays.asList(cards);
    Collections.shuffle(list);

    for(int i = 0; i < 52; i++) {
      String cardName = cards[i].getName();
      ImageIcon imageIcon = new ImageIcon("cards/" + cardName);
      Image image = imageIcon.getImage().getScaledInstance(45, 85,  java.awt.Image.SCALE_SMOOTH);
      ImageIcon scaledIcon = new ImageIcon(image);

      JLabel label = new JLabel(scaledIcon);
      panel.add(label);
    }
  }
}