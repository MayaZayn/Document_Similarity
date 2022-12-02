# Document_Similarity
Document similarity measures are very important in the field of information retrieval and search engines. They are measures that tell us how similar to documents are in terms of their word content. They can be used to find similar documents or to find how close a document is to a query on a search engine. There are many of such measures.

### In this program, I developed a StringSet class that stores a set of C++ strings 
* This class contains the following:
   * A **constructor** that takes a file name and loads the words in it (ignoring punctuation and turning text to lower case). 
   * A **constructor** that takes a string and loads it
   * Functions to **add a string** to the set, **remove a string** from the set, **clear** the entire set, return the **number of strings** in the set, and **output** all strings in the set. 
   * The **+ operator** overloaded to return the union of two StringSet objects. 
   * The *** operator** overloaded to return the intersection of two StringSet objects. 
   * A function to **compute the similarity** between the current StringSet and an input parameter of type StringSet. 
      
* Similarity is measured by binary cosine coefficient. The coefficient is a value between 0 and 1, where 1 indicates that the query (or document) is very 
similar to the document and 0 indicates that the query has no keywords in common with the document.

* Once we have a query Q represented as a set of words and a document D represented as a set of words (each word counts once even if repeated in document multiple times), the similarity between Q and D is computed by:
   * Sim = |Q ∩ D| The size of set of common words / (sqrt size of D * sqrt size of Q)
