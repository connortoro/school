import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class Grid extends JPanel {

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        g.setColor(Color.BLACK);

        // vertical lines
        for (int i = 0; i <= 10; i++) {
            int x = i * 50;
            g.drawLine(x, 0, x, 500);
        }

        // horizontal lines
        for (int i = 0; i <= 10; i++) {
            int y = i * 50;
            g.drawLine(0, y, 500, y);
        }

        //color bars
        Random random = new Random();
        for(int i = 0; i < 15; i++) {
            int red = random.nextInt(256);
            int green = random.nextInt(256);
            int blue = random.nextInt(256);
            Color color = new Color(red, green, blue);
            g.setColor(color);

            int y = random.nextInt(500);
            g.fillRect(i*30+5, 500-y, 10, y);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Centered Grid");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            Grid gridPanel = new Grid();
            JPanel panelContainer = new JPanel(new BorderLayout());
            gridPanel.setPreferredSize(new Dimension(500, 500));
            panelContainer.add(gridPanel, BorderLayout.CENTER);
            frame.add(panelContainer, BorderLayout.CENTER);

            JButton button = new JButton("Redraw");
            ActionListener buttonListener = new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    panelContainer.remove(gridPanel);
                    Grid newGridPanel = new Grid();
                    newGridPanel.setPreferredSize(new Dimension(500, 500));
                    panelContainer.add(newGridPanel, BorderLayout.CENTER);
                    panelContainer.revalidate();
                    panelContainer.repaint();
                }
            };
            button.addActionListener(buttonListener);
            frame.add(button, BorderLayout.SOUTH);


            frame.pack();
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        });
    }
}

