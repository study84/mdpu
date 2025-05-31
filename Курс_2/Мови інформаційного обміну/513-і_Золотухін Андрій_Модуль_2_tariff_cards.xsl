<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" encoding="UTF-8" indent="yes"/>
  <xsl:template match="/">
    <html><head><title>Тарифні плани</title>
      <style>
        body { font-family: Arial; background-color: #f8f8f8; }
        .card { background-color: white; border: 1px solid #ddd; border-radius: 8px; padding: 16px; margin: 10px; width: 300px; float: left; box-shadow: 2px 2px 6px rgba(0,0,0,0.1); }
        .title { font-size: 1.2em; font-weight: bold; margin-bottom: 8px; }
      </style>
    </head><body>
      <h2>Тарифні плани мобільного оператора</h2>
      <xsl:for-each select="operator/tariffs/tariff">
        <div class="card">
          <div class="title"><xsl:value-of select="name"/></div>
          <div>Ціна: <xsl:value-of select="price"/> <xsl:value-of select="currency"/></div>
          <div>Інтернет: <xsl:value-of select="internet"/> ГБ</div>
          <div>Хвилини: <xsl:value-of select="minutes"/></div>
          <div>SMS: <xsl:value-of select="sms"/></div>
          <div>Дата активації: <xsl:value-of select="activationDate"/></div>
        </div>
      </xsl:for-each>
      <div style="clear: both;"></div>
    </body></html>
  </xsl:template>
</xsl:stylesheet>