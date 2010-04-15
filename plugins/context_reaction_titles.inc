<?php
// $Id: context_reaction_titles.inc,v 1.1.2.1 2009/12/14 22:34:05 yhahn Exp $

/**
 * Expose themes as context reactions.
 */
class context_reaction_titles extends context_reaction {
  /**
   * Editor form.
   */
  function editor_form($context) {
    $form = $this->options_form($context);

    // Hide descriptions which take up too much space.
    unset($form['title']['#description']);
    unset($form['subtitle']['#description']);
    unset($form['class']['#description']);
    return $form;
  }

  /**
   * Submit handler for editor form.
   */
  function editor_form_submit($context, $values) {
    return $values;
  }

  /**
   * Allow admins to provide a section title, section subtitle and section class.
   */
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    $form = array(
      '#tree' => TRUE,
      '#title' => t('Titles'),
      'head_title' => array(
        '#title' => t('Head title'),
        '#description' => t('Modify window title'),
        '#type' => 'textfield',
        '#maxlength' => 255,
        '#default_value' => isset($values['head_title']) ? $values['head_title'] : '',
      ),
      'pagetitle' => array(
        '#title' => t('Page Title'),
        '#description' => t('Modify page title'),
        '#type' => 'textfield',
        '#maxlength' => 255,
        '#default_value' => isset($values['pagetitle']) ? $values['pagetitle'] : '',
      ),
      'pagetitle_hide' => array(
        '#title' => t('Hide Page Title'),
        '#description' => t('Modify page title'),
        '#type' => 'checkbox',
        '#maxlength' => 255,
        '#default_value' => isset($values['pagetitle_hide']) ? $values['pagetitle_hide'] : '',
      ),
    );
    return $form;
  }
  
  /**
   * Set 'section_title', and 'section_subtitle' if not set and merge all
   * additional classes onto the 'body_classes'.
   */
  function execute(&$vars) {
    $contexts = context_active_contexts();
    $classes = array();
    foreach ($contexts as $k => $v) {
    	echo "asdfasdF";
      if (!empty($v->reactions[$this->plugin]['head_title'])) {
        $vars['head_title'] = $v->reactions[$this->plugin]['head_title'];
      }

      if (!empty($v->reactions[$this->plugin]['pagetitle'])) {
        $vars['title'] = $v->reactions[$this->plugin]['pagetitle'];
      }

    }
  }
}
