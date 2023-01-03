package main;

public class Task {
	
	private String text;
	private boolean completed;
	
	public Task(){
		this.setText(null);
	}
	
	public Task(String text, boolean completed) {
		this.setText(text);
		this.setCompleted(completed);
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}

	public boolean isCompleted() {
		return completed;
	}

	public void setCompleted(boolean completed) {
		this.completed = completed;
	}
	

}
