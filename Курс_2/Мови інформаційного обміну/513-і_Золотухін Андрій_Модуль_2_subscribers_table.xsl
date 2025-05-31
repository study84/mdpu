<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" encoding="UTF-8" indent="yes"/>
  <xsl:template match="/">
    <html><head><title>Список абонентів</title>
      <style>
        table { border-collapse: collapse; width: 100%; font-family: Arial; }
        th, td { border: 1px solid #aaa; padding: 8px; text-align: left; }
        th { background-color: #f2f2f2; }
      </style>
    </head><body>
      <h2>Абоненти мобільного оператора</h2>
      <table>
        <tr><th>Ім’я</th><th>Телефон</th><th>Тариф</th><th>Активний</th><th>Дата підключення</th></tr>
        <xsl:for-each select="operator/subscribers/subscriber">
          <tr>
            <td><xsl:value-of select="name"/></td>
            <td><xsl:value-of select="phone"/></td>
            <td><xsl:variable name="tariffId" select="tariffRef"/>
                <xsl:value-of select="/operator/tariffs/tariff[@id=$tariffId]/name"/></td>
            <td><xsl:value-of select="@active"/></td>
            <td><xsl:value-of select="joined"/></td>
          </tr>
        </xsl:for-each>
      </table>
    </body></html>
  </xsl:template>
</xsl:stylesheet>