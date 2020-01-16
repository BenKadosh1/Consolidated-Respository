Assignment Prompt 

The Challenge: Build a large-scale image search engine!
You and your team of two Cornell Tech students are surely on the path to fame and fortune! You have been recruited by Google to disrupt Google Image Search by building a better search engine using novel statistical learning techniques.

The specifications are simple: We need a way to search for relevant images given a natural language query. For instance, if a user types "dog jumping to catch frisbee," your system will rank-order the most relevant images from a large database.

Here are some details:

During training, you have a dataset of 10,000 samples. Each sample has the following data available for learning:  

A 224x224 JPG image.  
A list of tags indicating objects appeared in the image.     
Feature vectors extracted using ResNet, a state-of-the-art Deep-learned CNN (You don't have to train or run ResNet -- we are providing the features for you). See here for the illustration of the ResNet-101 architecture. The features are extracted from pool5 and fc1000 layer.  
A five-sentence description, used to train your search engine.  

During testing, your system matches a single five-sentence description against a pool of 2,000 candidate samples from the test set. Each sample has:  

A 224x224 JPEG image.   
A list of tags for that image.  
ResNet feature vectors for that image.  
Output: For each description, your system must rank-score each testing image with the likelihood of that image matches the given sentence. Your system then returns the name of the top 20 relevant images, delimited by space. See "sample_submission.csv" on the data page for more details on the output format.   
Evaluation metric: There are 2,000 descriptions, and for each description, you must compare against the entire 2,000-image test set. That is, rank-order test images for each test description. We will use MAP@20 as the evaluation metric. If the corresponding image of a description is among your algorithm's 20 highest scoring images, this metric gives you a certain score based on the ranking of the corresponding image. Please refer to the evaluation page for more details.    
Use all of your skills, tools, and experience. It is OK to use libraries like numpy, scikit-learn, pandas, etc., as long as you cite them. Use cross-validation on training set to debug your algorithm. Submit your results to the Kaggle leaderboard and send your complete writeup to EasyChair. The data you use --- and the way you use the data --- is completely up to you.    

The best teams (of two Cornell Tech students, recall) might use visualization techniques for debugging (e.g., show top images retrieved by your algorithm and see whether they make sense or not), preprocessing, a nice way to compare tags and descriptions, leveraging visual features and combining them with tags and descriptions, supervised and/or unsupervised learning to best understand how to best take advantage of each data source available to them.  

The best reports will be professionally written. We suggest including an Abstract, followed by an Introduction section including motivations of your method and a detailed description of each step in your pipeline / framework you used for this task. Then, include a detailed Experiment section and a Results section. If time permits, a Background / Related Work section can help to point out the relevant work in the image retrieval literature.
