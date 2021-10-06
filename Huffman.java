package huffman_coding;

import java.util.*;
import java.util.PriorityQueue;
class Node
{
	char ch;
	int freq;
	Node left;
	Node right;
	Node(char ch, int freq)
	{
		this.ch=ch;
		this.freq=freq;
	}
	Node(char ch, int freq, Node left, Node right)
	{
		this.ch =ch;
		this.freq=freq;
		this.left =left;
		this.right = right;
	}
}
public class program
{
	
	
	public static void encode(Node root , String str, Map<Character,String>Huffman_code)
	{
		if(root==null)
			return;
		if(root.left==null && root.right==null)
		{
			Huffman_code.put(root.ch, str);
		}
		encode(root.left, str+'0',Huffman_code);
		encode(root.right,str+'1',Huffman_code);
	}
	
	public static int decode(Node root, int index, StringBuilder sb)
	{
		if(root == null)
			return index;
		if (root.left==null && root.right==null)
		{
			System.out.print(root.ch);
			return index;
		}
		
		index++;
		
		if(sb.charAt(index)=='0')
			index = decode(root.left,index,sb);
		else
			index = decode(root.right,index,sb);
		
		return index;
		
	}
	public static void buildHuffmantree(String text)
	{
		Map<Character, Integer> freq = new HashMap<>();
		
		
		for(char c: text.toCharArray())
		{
			freq.put(c, freq.getOrDefault(c,0)+1);
		}
		PriorityQueue<Node>pq = new PriorityQueue<>(Comparator.comparingInt(l->l.freq));
		
		for(var entry : freq.entrySet())
		{
			pq.add(new Node(entry.getKey(),entry.getValue()));
		}
		
      while(pq.size()!=1)
      {
    	  Node left = pq.poll();
    	  Node right = pq.poll();
    	  int sum_freq = left.freq + right.freq;
    	  pq.add(new Node('\0',sum_freq,left,right)); 
      }
      Node root = pq.peek();
      
      Map<Character,String> Huffman_code = new HashMap<>();
      encode(root,"",Huffman_code);
      
      
      System.out.println("Huffman codes are: "+Huffman_code);
      System.out.println("original string: "+text);
      StringBuilder sb = new StringBuilder();
      for(char ch : text.toCharArray())
      {
    	  sb.append(Huffman_code.get(ch));
    	  
      }
      
      System.out.println("Encoded string is: "+sb);
      System.out.print("Decoded Huffman code is: " );
      int index = -1;
      while(index<sb.length()-2)
      {
    	  index = decode(root,index,sb);
      }
		
	}

	public static void main(String args[])
	{
		String text = "aa bb ccc dddd";
		buildHuffmantree(text);
	}
}
