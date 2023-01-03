package main;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame implements ActionListener{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	//Constants
	final String fileName = "listFile.txt";
	
	//Variables used
	File file;
	ArrayList<Task> taskList;
	int item; //editing item number
	
	//Buttons
	JButton[] mark;
	JButton[] erase;
	JButton[] edit;
	
	//Textfields
	JTextField newTask;
	JTextField editTask;
	
	//Panels
	private JPanel listPanel;
	private JPanel bottomPanel;

	/* MAIN CONSTRUCTOR */
	public GUI() {
		
		loadList();
				
		/*----------MAIN FRAME DATA----------*/
		this.setTitle("To-do list");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new BorderLayout());
		
		
		//Top panel, just the title
		JPanel titlePanel = new JPanel();
		JLabel title = new JLabel();
		
		title.setText("TO DO LIST");
		title.setFont(new Font("Arial", Font.BOLD, 30));
		
		titlePanel.add(title);
		this.add(titlePanel, BorderLayout.NORTH);

		
		//Center panel
		this.listPanel = centerPanel(taskList);
		this.add(listPanel, BorderLayout.CENTER);
		
		//bottom panel
		this.bottomPanel = bottomPanel();
		this.add(bottomPanel, BorderLayout.SOUTH);
		
		//This goes to the end
		this.setVisible(true);
		this.pack();
		
		//This goes to the very end
		this.setLocationRelativeTo(null);;
	}
	
	/* LIST PANEL METHOD*/
	public JPanel centerPanel(ArrayList<Task> taskList) {
		
		this.taskList = taskList;
		
		//Create the panel, size of the list+1 with a "Mark/Unmark" button and an "Erase" button
		JPanel centerPanel = new JPanel();
		centerPanel.setLayout(new GridLayout(0, 1));
		
		//Create arrays of variables
		JLabel[] tasks = new JLabel[taskList.size()];
		mark = new JButton[taskList.size()];
		erase = new JButton[taskList.size()];
		edit = new JButton[taskList.size()];
		
		if(taskList.size() > 0) {
			
			//For every TASK in the Array...
			for(int i = 0; i < taskList.size(); i++) {
				JPanel taskContainer = new JPanel();
				taskContainer.setLayout(new FlowLayout());
				
				//1. Create a label with the indexed task, and light gray color if it's completed
				tasks[i] = new JLabel();
				tasks[i].setText(i+1+". "+taskList.get(i).getText()+"   ");
				tasks[i].setFont(new Font("Arial", Font.PLAIN, 25));
				if(taskList.get(i).isCompleted()) {
					tasks[i].setForeground(Color.LIGHT_GRAY);
				}
				
				taskContainer.add(tasks[i]);
				
				//2. Create a button to mark/unmark its task as completed
				ImageIcon check = new ImageIcon("mark.png");
				mark[i] = new JButton();
				mark[i].setIcon(check);
				mark[i].addActionListener(this);
				//mark[i].setBorderPainted(false);
				//mark[i].setContentAreaFilled(false);
				mark[i].setFocusable(true);
				mark[i].setBackground(Color.GREEN);
				mark[i].setPreferredSize(new Dimension(32, 32));
				
				taskContainer.add(mark[i]);
				
				//3. Create a button to edit
				ImageIcon pencil = new ImageIcon("edit.png");
				edit[i] = new JButton();
				edit[i].setIcon(pencil);
				edit[i].addActionListener(this);
				//edit[i].setBorderPainted(false);
				//edit[i].setContentAreaFilled(false);
				edit[i].setBackground(Color.YELLOW);
				edit[i].setFocusable(false);
				edit[i].setPreferredSize(new Dimension(32, 32));
				
				taskContainer.add(edit[i]);
								
				//4. Create a button to delete
				ImageIcon cross = new ImageIcon("cross.png");
				erase[i] = new JButton();
				erase[i].setIcon(cross);
				erase[i].addActionListener(this);
				//erase[i].setBorderPainted(false);
				//erase[i].setContentAreaFilled(false);
				erase[i].setBackground(Color.RED);
				erase[i].setFocusable(false);
				erase[i].setPreferredSize(new Dimension(32, 32));
				
				taskContainer.add(erase[i]);
				
				centerPanel.add(taskContainer);
			}
		}
		
		return centerPanel;
	}
	
	/* CREATE NEW TASK METHOD */
	public JPanel bottomPanel() {
		
		bottomPanel = new JPanel();
		//Label
		JLabel label = new JLabel("New task: ");
		label.setFont(new Font ("Arial", Font.PLAIN, 20));
		bottomPanel.add(label);
		
		//Field
		newTask = new JTextField();
		newTask.addActionListener(this);
		newTask.setFont(new Font ("Arial", Font.PLAIN, 20));
		newTask.setPreferredSize(new Dimension(600, 35));
		bottomPanel.add(newTask);
		
		return bottomPanel;
	}
	
	/* LOAD/CREATE LIST METHOD */
	public void loadList() {
		
		file = new File(fileName);
		taskList = new ArrayList<Task>();
		
		//Assume no error has occured
		try {
			
			//It creates the file if it didn't exist
			if(file.createNewFile()) {
				System.out.println("File "+file.getName()+" created");
				
			//It only reads the existing file
			}else {
				Scanner reader = new Scanner(file);
				
				//While there's a next line in the file
				while(reader.hasNextLine()) {
					//Init new task
					Task currentTask = new Task();
					
					//Reads the next line
					String line = reader.nextLine();
					
					//Splits it in two, separated by ";;"
					currentTask.setText(line.split(";;", 2)[0]);
					try {
						currentTask.setCompleted(Boolean.valueOf(line.split(";;",2)[1]));
					}catch(Exception e) {
						System.out.println("ERROR: There's something wrong with the file");
						reader.close();
						return;
					}
					
					//Add them to the task list
					taskList.add(currentTask);
				}
				//Closes the fucking scanner
				reader.close();
				System.out.println("Succesfully loaded");
			}
		
		//There's been a fucking error 
		}catch(IOException e) {
			System.out.println("An error has occurred");
			e.printStackTrace();
		}
		
	}
	
	/* SAVE LIST CHANGES METHOD */
	public void saveList() {
		try {
			//First we have to delete the entire fucking file
			file.delete();
			file.createNewFile();
			
			FileWriter writer = new FileWriter(fileName);
			
			for(Task t : taskList) {
				String stask = t.getText()+";;"+String.valueOf(t.isCompleted());
				writer.write(stask+"\n");
			}
			
			writer.close();
			
		//There's been a fucking error 
		}catch(IOException e) {
			System.out.println("An error has occurred");
			e.printStackTrace();
			
		}
	}
	
	/* UPDATE GUI METHOD */
	public void updateGUI() {
		
		this.remove(listPanel);
		this.remove(bottomPanel);
		
		this.listPanel = centerPanel(taskList);
		this.bottomPanel = bottomPanel();
		
		this.add(listPanel, BorderLayout.CENTER);
		this.add(bottomPanel, BorderLayout.SOUTH);
		
		//At the end
		this.setVisible(true);
		this.pack();
		
		this.revalidate();
	}
	
	/* EDITING PANEL METHOD */
	public JPanel editingCenterPanel(ArrayList<Task> taskList, int item) {
		
		this.taskList = taskList;
		this.item = item;
		
		//Create the panel, size of the list+1 with a "Mark/Unmark" button and an "Erase" button
		JPanel centerPanel = new JPanel();
		centerPanel.setLayout(new GridLayout(0, 1));
		
		//Create arrays of variables
		JLabel[] tasks = new JLabel[taskList.size()];
		mark = new JButton[taskList.size()];
		erase = new JButton[taskList.size()];
		edit = new JButton[taskList.size()];
		
		
		if(taskList.size() > 0) {
			
			//For every TASK in the Array...
			for(int i = 0; i < taskList.size(); i++) {
				JPanel taskContainer = new JPanel();
				taskContainer.setLayout(new FlowLayout());
				
				//1. Create a label with the indexed task, and light gray color if it's completed
				tasks[i] = new JLabel();
				
				//if it's the selected item, allow to edit
				if(i == item) {
					
					tasks[i].setText(i+1+". ");
					tasks[i].setFont(new Font("Arial", Font.PLAIN, 25));
					
					
					editTask = new JTextField();
					editTask.setText(taskList.get(i).getText());
					editTask.setFont(new Font("Arial", Font.PLAIN, 25));
					editTask.addActionListener(this);
					
					taskContainer.add(tasks[i]);
					taskContainer.add(editTask);
					
					centerPanel.add(taskContainer);
					
					continue;
					
				}else {
					
					tasks[i].setText(i+1+". "+taskList.get(i).getText()+"   ");
					tasks[i].setFont(new Font("Arial", Font.PLAIN, 25));
					if(taskList.get(i).isCompleted()) {
						tasks[i].setForeground(Color.LIGHT_GRAY);
					}
					
					taskContainer.add(tasks[i]);
					
				}
				
				
				//THE BUTTON IS DISABLED
				ImageIcon check = new ImageIcon("mark.png");
				mark[i] = new JButton();
				mark[i].setIcon(check);
				//mark[i].addActionListener(this);
				mark[i].setBorderPainted(false);
				mark[i].setContentAreaFilled(false);
				mark[i].setFocusable(true);
				mark[i].setPreferredSize(new Dimension(30, 30));
				
				taskContainer.add(mark[i]);

				//THE BUTTON IS DISABLED
				ImageIcon pencil = new ImageIcon("edit.png");
				edit[i] = new JButton();
				edit[i].setIcon(pencil);
				edit[i].addActionListener(this);
				edit[i].setBorderPainted(false);
				edit[i].setContentAreaFilled(false);
				edit[i].setFocusable(false);
				edit[i].setPreferredSize(new Dimension(30, 30));
				
				taskContainer.add(edit[i]);

				//THE BUTTON IS DISABLED
				ImageIcon cross = new ImageIcon("cross.png");
				erase[i] = new JButton();
				erase[i].setIcon(cross);
				//erase[i].addActionListener(this);
				erase[i].setBorderPainted(false);
				erase[i].setContentAreaFilled(false);
				erase[i].setFocusable(false);
				erase[i].setPreferredSize(new Dimension(30, 30));
				
				taskContainer.add(erase[i]);
				
				centerPanel.add(taskContainer);
			}
		}
		
		return centerPanel;
	}
	
	
	
	/* THE LISTENER METHOD */
	@Override
	public void actionPerformed(ActionEvent e) {
		
		//Add new text bar
		if(e.getSource()==newTask) {
			taskList.add(new Task(newTask.getText(), false));
			saveList();
			updateGUI();
			return;
		}
		
		for(int i = 0; i < taskList.size(); i++) {
			
			//Delete a task
			if(e.getSource()==erase[i]) {
				taskList.remove(i);
				saveList();
				updateGUI();
				return;
			}
			
			//Mark/Unmark a task
			if(e.getSource()==mark[i]) {
				Task found = taskList.get(i);
				found.setCompleted(!found.isCompleted());
				taskList.set(i, found);
				saveList();
				updateGUI();
				return;
			}
			
			//Edit a task
			if(e.getSource()==edit[i]) {				
				this.remove(listPanel);
				this.remove(bottomPanel);
				
				this.listPanel = editingCenterPanel(taskList, i);
				this.bottomPanel = bottomPanel();
				
				this.add(listPanel, BorderLayout.CENTER);
				this.add(bottomPanel, BorderLayout.SOUTH);
				
				//At the end
				this.setVisible(true);
				this.pack();
				
				this.revalidate();
				return;
			}
			
		}
		
		//SAVE edited task
		if(e.getSource()==editTask) {
			
			taskList.get(item).setText(editTask.getText());

			saveList();
			updateGUI();
			return;
		}
	}

}
