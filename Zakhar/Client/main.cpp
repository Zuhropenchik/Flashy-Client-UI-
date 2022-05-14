#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <string>
#include "Client.h"
#include "Serializer.h"
#include "Manager.h"
#include <QApplication>
#include "startpage.h"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>


int main(int argc, char *argv[]) {
    unsigned short port = 8080;
    auto const text = "Hello, VLAD!";

    std::string jsonka = "{\n"
                         "  \"user_id\": \"137\",\n"
                         "  \"name\": \"Boris\",\n"
                         "  \"login\": \"Boris17\",\n"
                         "  \"password\": \"Demon123\",\n"
                         "  \"categories\": [ \"2\", \"3\"],\n"
                         "  \"notes_id\": [ \"12\", \"17\"],\n"
                         "  \"notes_name\": [\"Example 1\", \"Example 2\"]\n"
                         "}";
    std::string host = "127.0.0.1";
    User example = User("Example user", {"Example note 1", "Example note 2", "Example note 3"});
    net::io_context ioc;
    Manager manager(ioc);
    manager.ChangeUser(example);
    Serializer ser;
    ser.user_deserialize(jsonka);
    QApplication a(argc, argv);
    StartPage w;
    w.show();

    return a.exec();

}