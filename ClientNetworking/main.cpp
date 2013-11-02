#include "Client.h"
#include <QtCore/QCoreApplication>

int main(int argc, char** argv){
  QCoreApplication app(argc, argv);
  Client client;
  client.start("127.0.0.1", 8888);
  Evaluation e;
  e.setRating(2);
  e.setId(0);
  e.setTaskId(2);
  e.setComment("This is an example comment");
  client.deleteEval(e);
  return app.exec();
}
