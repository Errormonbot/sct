One-dimensional dataset as an illustration of the gaussian influence:
rbf.gauss <- function(gamma=1.0) {
function(x) {
exp(-gamma * norm(as.matrix(x),"F")^2 )
}
}
D <- matrix(c(-3,1,4), ncol=1) # 3 datapoints
N <- length(D[,1])
xlim <- c(-5,7)
plot(NULL,xlim=xlim,ylim=c(0,1.25),type="n")
points(D,rep(0,length(D)),col=1:N,pch=19)
x.coord = seq(-7,7,length=250)
gamma <- 1.5
for (i in 1:N) {
points(x.coord, lapply(x.coord - D[i,], rbf.gauss(gamma)), type="l", col=i)
}


The value of gamma controls how far or how little the influnce of each datapoint is felt:
plot(NULL,xlim=xlim,ylim=c(0,1.25),type="n")
points(D,rep(0,length(D)),col=1:N,pch=19)
x.coord = seq(-7,7,length=250)
gamma <- 0.25
for (i in 1:N) {
points(x.coord, lapply(x.coord - D[i,], rbf.gauss(gamma)), type="l", col=i)
}
