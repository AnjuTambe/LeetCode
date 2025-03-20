#Homework 8
#Handwriting recognition with NNs
#course : Algorithm
#import the library

import numpy as np
import os


#Initializes the class of the neural network with given layer sizes and learning rate.
# Uses He initialization for weights to maintain stability.
        
# Parameters:
#- layer_sizes (list): List of integers representing the number of neurons per layer.
#- learning_rate (float): The rate at which the model learns (default 0.01).



# Grayscale mapping for ASCII digits
GRAYSCALE = " .:-=+*#%@"

class NeuralNetwork:
    def __init__(self, layer_sizes, learning_rate=0.01):
        self.layer_sizes = layer_sizes
        self.learning_rate = learning_rate

        # He Initialization for weight stability
        self.weights = [np.random.randn(y, x) * np.sqrt(2.0 / x) for x, y in zip(layer_sizes[:-1], layer_sizes[1:])]
        self.biases = [np.zeros((y, 1)) for y in layer_sizes[1:]]
    
    # here I Applied the ReLU activation function.
    def relu(self, x):
        return np.maximum(0, x)
    #Computes the derivative of the ReLU function
    def relu_derivative(self, x):
        return (x > 0).astype(float)
    #Applies the softmax function to convert logits into probability distributions.
    def softmax(self, x):
        exp_x = np.exp(x - np.max(x, axis=0, keepdims=True))
        return exp_x / np.sum(exp_x, axis=0, keepdims=True)

    #Performs forward propagation through the network.
    def forward(self, x):
        activations = [x]
        for i in range(len(self.weights) - 1):
            x = self.relu(np.dot(self.weights[i], x) + self.biases[i])
            activations.append(x)
        x = self.softmax(np.dot(self.weights[-1], x) + self.biases[-1])
        activations.append(x)
        return activations
    
    #Performs backpropagation to compute weight and bias gradients.
    # Uses gradient descent to update weights and biases.
        
    def backpropagation(self, x, y, activations):
        grads_w = [np.zeros_like(w) for w in self.weights]
        grads_b = [np.zeros_like(b) for b in self.biases]

        output_error = activations[-1] - y
        grads_w[-1] = np.dot(output_error, activations[-2].T)
        grads_b[-1] = output_error

        for l in range(2, len(self.layer_sizes)):
            delta = np.dot(self.weights[-l+1].T, output_error) * self.relu_derivative(activations[-l])
            grads_w[-l] = np.dot(delta, activations[-l-1].T)
            grads_b[-l] = delta
            output_error = delta

        for i in range(len(self.weights)):
            self.weights[i] -= self.learning_rate * grads_w[i]
            self.biases[i] -= self.learning_rate * grads_b[i]

  # Trains the neural network using mini-batch gradient descent.
    def train(self, X, Y, epochs=100, batch_size=16):
        for epoch in range(epochs):
            self.learning_rate = 0.01 * (0.99 ** epoch)  # Learning rate decay
            indices = np.random.permutation(len(X))  # Shuffle data
            X, Y = X[indices], Y[indices]

            for i in range(0, len(X), batch_size):
                X_batch = X[i:i + batch_size]
                Y_batch = Y[i:i + batch_size]

                for x, y in zip(X_batch, Y_batch):
                    activations = self.forward(x.reshape(-1, 1))
                    self.backpropagation(x.reshape(-1, 1), y.reshape(-1, 1), activations)
    
    #Predicts the class of a given input image.
    def predict(self, x):
        activations = self.forward(x.reshape(-1, 1))
        prediction = np.argmax(activations[-1])
        return prediction, activations[-1]

# Converts an ASCII image into a numerical array representing pixel intensity.
def process_ascii_image(file_path):
    with open(file_path, "r") as file:
        lines = file.readlines()

    image_data = []
    for line in lines:
        for char in line.strip():
            image_data.append(GRAYSCALE.index(char) / (len(GRAYSCALE) - 1))

    if len(image_data) != 784:
        image_data = image_data[:784] + [0] * (784 - len(image_data))

    return np.array(image_data)

#Loads images and labels from a specified folder.
def load_data(folder):
    images, labels = [], []
    for file_name in os.listdir(folder):
        if file_name.endswith(".txt"):
            label = int(file_name.split("_")[0])
            images.append(process_ascii_image(os.path.join(folder, file_name)))
            labels.append(label)

    images = np.array(images)
    labels = np.eye(10)[labels]
    return images, labels

if __name__ == "__main__":
    print(f"Network layers: {', '.join(map(str, [784, 512, 256, 128, 64, 10]))}")

    print("Loading training data...")
    train_images, train_labels = load_data("training/")
    print(f"{len(train_images)} training samples")

    nn = NeuralNetwork(layer_sizes=[784, 512, 256, 128, 64, 10], learning_rate=0.01)
    nn.train(train_images, train_labels, epochs=100)

    print("Loading testing data...")
    test_images, test_labels = load_data("testing/")
    print(f"{len(test_images)} testing samples")

    print("\nTesting...........")

    correct = 0
    results = []

    for i, (img, label) in enumerate(zip(test_images, test_labels)):
        prediction, confidence_scores = nn.predict(img)
        actual = np.argmax(label)
        confidence = confidence_scores[prediction][0] * 100

        file_name = f"{actual}_{i}.txt"
        results.append(f"{file_name} assessed as {prediction} ({confidence:.6f}%)")

        if prediction == actual:
            correct += 1

    print("\n".join(results))
    print(f"\n✅ Successful rate is: {(correct / len(test_labels)) * 100:.2f}%")
