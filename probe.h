#ifndef ENDOSCOPE_PROBE_H
#define ENDOSCOPE_PROBE_H

#include <qobject.h>


namespace Endoscope {

class ObjectListModel;
class ObjectTreeModel;

class Probe : public QObject
{
  Q_OBJECT
  public:
    static Probe* instance();
    static bool isInitialized();

    static void objectAdded( QObject *obj );
    static void objectRemoved( QObject *obj );
    static void connectionAdded( const QObject *sender, const char* signal, const QObject *receiver, const char *method, Qt::ConnectionType type );
    static void connectionRemoved( const QObject *sender, const char *signal, const QObject *receiver, const char *method );

    ObjectListModel *objectListModel() const;
    ObjectTreeModel *objectTreeModel() const;

  protected:
    bool eventFilter(QObject *receiver, QEvent *event );

  private slots:
    void delayedInit();

  private:
    Probe( QObject* parent = 0 );
    static Probe* s_instance;

    ObjectListModel *m_objectListModel;
    ObjectTreeModel *m_objectTreeModel;
};

}

#endif // ENDOSCOPE_PROBE_H
