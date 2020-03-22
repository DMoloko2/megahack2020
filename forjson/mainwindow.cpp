    #include "mainwindow.h"
    #include "ui_mainwindow.h"
    #include <QDebug>
    #include <QJsonDocument>
    #include <QJsonObject>
    #include <QJsonArray>



    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
    {
        ui->setupUi(this);

        web=new QWebSocketServer("Server",QWebSocketServer::NonSecureMode);
        web->listen(QHostAddress::Any, 1796);
        connect(web, SIGNAL(newConnection()),this, SLOT(onNewConnection()));










        connect(this,SIGNAL(sig1(QStringList)),this,SLOT(slot1(QStringList)));

        QObject::connect(&soc, SIGNAL(connected()), SLOT(slotConnected()));
        QObject::connect(&soc, SIGNAL(readyRead()), SLOT(slotReadyRead()));
        QObject::connect(&soc, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError))
        );



    }

    /*virtual*/ void MainWindow::slotNewConnection()            //слот для нового подлючения
    {
    pClientSocket = m_ptcpServer->nextPendingConnection();
    connect(pClientSocket, SIGNAL(disconnected()),pClientSocket, SLOT(deleteLater())) ;
    connect(pClientSocket, SIGNAL(readyRead()),this, SLOT(slotReadClient()));
    //sendToClient(pClientSocket,"yes");




    }

    MainWindow::~MainWindow()
    {
        file.setFileName("file.txt");
        file.open(QIODevice::ReadWrite |  QIODevice::Truncate);
       QByteArray b;
       QString h;
        for (int o=0;o<vec.size();o++)
        {
            h=QString::number(vec.at(o));
            h+="\n";
            b=h.toUtf8();
            file.write(b);
        }
        soc.close();
        file.close();
        delete ui;
        delete web;
    }

    void MainWindow::reqq(const char *a)             //запрос в БД
    {
        qDebug()<<a;


        QNetworkRequest request(apiUrl);
        reply = manager.post(request,a);
       /* QObject::connect(reply, SIGNAL(finished()),this, SLOT(getReplyFinished()));
        QObject::connect(reply, SIGNAL(readyRead()), this, SLOT(readyReadReply()));*/
    }

    void MainWindow::getReplyFinished()             //после запроса в БД clicHouse
    {

        reply->deleteLater();
    }

    void MainWindow::onNewConnection()              //для websocketa
    {
        auto pSocket = web->nextPendingConnection();

        pSocket->setParent(this);

        //qDebug()<<"s";
        connect(pSocket, &QWebSocket::textMessageReceived,
                this, &MainWindow::processMessage);
        connect(pSocket, &QWebSocket::disconnected,
                this, &MainWindow::socketDisconnected);





    }

    void MainWindow::slotReadClient()               //чтение данных из сокета с распредилителя
    {


            QString k (pClientSocket->readAll());
            QStringList list;
                if(k.size()>1)
                {
                list=k.split("/");
                }


                emit sig1(list);

        //pClientSocket->readAll());




    }

    void MainWindow::readyReadReply()       //ответ на запрос в БД clickHouse
    {
        QString data(reply->readAll().toStdString().data());

       qDebug()<<data;

       /* QJsonDocument doc=QJsonDocument::fromJson(reply->readAll());
        QJsonArray ar=doc.array();


        ui->pushButton->setText(ar.at(0).toString());
        qDebug()<<ar.at(0).toString()<<ar.at(1)<<ar.at(2)<<ar.at(3);*/
    }

    void MainWindow::on_pushButton_clicked()
    {
        ui->pushButton->setDisabled(true);
        QString m;
        m= "http://";
        m+=ui->lineEdit->text();
        m+=":";
        QString k=QString::number(ui->spinBox->value());
        m+=k;
        m+="/?user=";
        m+=ui->lineEdit_3->text();
        m+="&password=";
        m+=ui->lineEdit_4->text();
        apiUrl.setUrl(m);
        //this->hide();
        sqlConnect();
        refreshDB();
        soc.connectToHost(ui->lineEdit_2->text(),ui->spinBox_2->value());

        ui->label_16->setText("ClickHouse connected");

        m_ptcpServer=new QTcpServer(this);
        connect(m_ptcpServer, SIGNAL(newConnection() ),this, SLOT(slotNewConnection())) ;
        if (!m_ptcpServer->listen(QHostAddress::Any, ui->spinBox_3->value()))
        {
        QMessageBox::critical(nullptr,
        "Server Error",
        "Unable to start the server:"
        + m_ptcpServer->errorString()) ;
        m_ptcpServer->close( );
        }
       // m_ptcpServer->waitForNewConnection(9999999);
        //reqq("DROP TABLE test.opc");
        //reqq("CREATE TABLE test.opc (timestamp DateTime DEFAULT NOW(),typee Int16,param Int16,value t32,prev Float32) ENGINE = MergeTree() ORDER BY (timestamp) SETTINGS index_granularity = 8192");
    }

    void MainWindow::slot1(QStringList list)
    {


        ui->label->setText("sd");
        float porog=1;

        for (int i=0;i<list.size();i++)
        {
            if(!list.at(i).isEmpty())
            {

               bool t= list.at(i).toInt()<vec.at(count);
               count++;
               //qDebug()<<count;
               if(count>=vec.size())
               {

                   count=0;
               }

               QString s,reqqqq,p,por;
               s=QString::number(typee);
               p=QString::number(count);
               por=QString::number(porog);
               //qDebug()<<s<<p;
               reqqqq="INSERT INTO test.opc (typee, param, value,prev) VALUES (";
               reqqqq+=s;
               reqqqq+=",";
               reqqqq+=p;
               reqqqq+=",";
               reqqqq+=list.at(i);
               reqqqq+=",";


               if(!t)
               {
                   porog=list.at(i).toFloat()/vec.at(count);
                   qDebug()<<porog<<list.at(i).toInt()<<"/"<<vec.at(count);
                   por=QString::number(porog);
                   QString h;
                   h=s;
                   h+=" ";
                   h+=p;
                   h+=" ";
                   h+=por;
                   h+=" ";
                   QByteArray bu(h.toUtf8());
                   //qDebug()<<h;
                   sendTelega(bu);
               }

               reqqqq+=por;
               reqqqq+=")";
               std::string b=reqqqq.toStdString();
               const char *v=b.data();
               reqq(v);


            }
        }
    }

    void MainWindow::sendToClient(QTcpSocket* pSocket, const QString& str)          //отправка клиенту сокета для распредилителя
    {
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size()-sizeof(quint16));
    pSocket->write(arrBlock);
    }

    void MainWindow::sendTelega(QByteArray a)                                       //отправка даннаых в Телеграмм
    {


        soc.write(a);


    }

    bool MainWindow::sqlConnect()                                                   //Подключение к sql
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");

           db.setHostName(ui->lineEdit_5->text());
           db.setDatabaseName("progdb");
           db.setUserName(ui->lineEdit_6->text());
           db.setPassword(ui->lineEdit_7->text());
           bool ok = db.open();
           return ok;
    }

    void MainWindow::processMessage(const QString &message)
    {
        qDebug()<<message;
        if(message!="")
        {
            refreshDB();
        }
    }

    void MainWindow::slotReadyRead()                                                  //чтение при отправке на телегу
    {

               qDebug()<<soc.readAll();

    }



void MainWindow::slotConnected()    //конект с телеграмом
{
    ui->label_14->setText("connect To Telegramm");

}
void MainWindow::slotError(QAbstractSocket::SocketError err)            //ошибки при конекте с телегой
{
QString strError =
"Error: " + (err == QAbstractSocket::HostNotFoundError ?
"The host was not found." :
err == QAbstractSocket::RemoteHostClosedError ?
"The remote host is closed." :
err == QAbstractSocket::ConnectionRefusedError ?
"The connection was refused." :
QString(soc.errorString())
);
qDebug()<<strError;
}

void MainWindow::socketDisconnected()
{

}

void MainWindow::refreshDB()
{
    QSqlQuery query;
    typee=ui->comboBox->currentIndex();
    QString j=QString::number(typee);
    QString l;
    l+="SELECT porog FROM temp WHERE type=";
    l+=j;
    query.exec(l);
    query.next();
    //qDebug()<<query.size();
    for(int e=0;e<query.size();e++)
    {
    vec.push_back(query.value(0).toInt());
    query.next();
    //qDebug()<<vec.at(e);
    }
    ui->label_15->setText("SQL connected");
}
