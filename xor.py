import math
import numpy
import random
INPUT_NODES=2
OUTPUT_NODES=1
HIDDEN_NODES=2
MAX_ITERATIONS=130000
LEARNING_RATE=2
print("Neural Network Program")
class network:
    def __init__(self,input_nodes,hidden_nodes,output_nodes,learning_rate):
        self.input_nodes=input_nodes
        self.hidden_nodes=hidden_nodes
        self.output_nodes=output_nodes
        self.total_nodes=input_nodes+hidden_nodes+output_nodes
        self.learning_rate=learning_rate
        self.values=numpy.zeros(self.total_nodes)
        self.expectedValues=numpy.zeros(self.total_nodes)
        self.thresholds=numpy.zeros(self.total_nodes)
        self.weights=numpy.zeros((self.total_nodes,self.total_nodes))
        random.seed(10000)
        for i in range(self.input_nodes,self.total_nodes):
            self.thresholds[i]=random.random()/random.random()
            for j in range(i+1,self.total_nodes):
                self.weights[i][j]=random.random()*2

    def process(self):
        for i in range(self.input_nodes,self.input_nodes+self.hidden_nodes):
            W_i=0.0
            for j in range(self.input_nodes):
                W_i+=self.weights[j][i]*self.values[j]
            W_i-=self.thresholds[i]
            self.values[i]=1/(1+math.exp(-W_i))
        for i in range(self.input_nodes+self.hidden_nodes,self.total_nodes):
            W_i=0.0
            for j in range(self.input_nodes,self.input_nodes+self.hidden_nodes):
                W_i+=self.weights[j][i]*self.values[j]
            W_i-=self.thresholds[i]
            self.values[i]= 1/(1+math.exp(-W_i))

    def processErrors(self):
        sumOfSquaredErrors=0.0
        for i in range(self.input_nodes,self.hidden_nodes,self.total_nodes):
            error=self.expectedValues[i]-self.values[i]
            sumOfSquaredErrors+=math.pow(error,2)
            outputErrorGradient=self.values[i]*(1-self.values[i])*error
            for j in range(self.input_nodes,self.input_nodes+self.hidden_nodes):
                delta = self.learning_rate*self.values[j]*outputErrorGradient
                self.weights[j][i]+=delta
                hiddenErrorGradient = self.values[j]*(1-self.values[j])*outputErrorGradient*self.weights[j][i]
                for k in range(self.input_nodes):
                    delta=self.learning_rate*self.values[k]*hiddenErrorGradient
                    self.weights[k][j]+=delta
                delta=self.learning_rate*-1*hiddenErrorGradient
                self.thresholds[j]+=delta
                delta=self.learning_rate*-1*outputErrorGradient
                self.thresholds[i]+=delta
            return sumOfSquaredErrors


class sampleMaker:
    def __init__(self,network):
        self.counter=0
        self.network=network
    def setXor(self,x):
        if x==0:
            self.network.values[0]=1
            self.network.values[1]=1
            self.network.expectedValues[4]=0
        elif x==1:
            self.network.values[0]=0
            self.network.values[1]=1
            self.network.expectedValues[4]=1
        elif x==2:
            self.network.values[0]=1
            self.network.values[1]=0
            self.network.expectedValues[4]=1
        else:
            self.network.values[0]=0
            self.network.values[1]=0
            self.network.expectedValues[4]=0
    def setNextTrainingData(self):
        self.setXor(self.counter%4)
        self.counter+=1

net =network(INPUT_NODES,HIDDEN_NODES,OUTPUT_NODES,LEARNING_RATE)
samples=sampleMaker(net)
for i in range(MAX_ITERATIONS):
    samples.setNextTrainingData()
    net.process()
    error=net.processErrors()
    if i>(MAX_ITERATIONS-5):
        output=(net.values[0],net.values[1],net.values[4],net.expectedValues[4],error)
        print(output)
print(net.weights)
print(net.thresholds)
