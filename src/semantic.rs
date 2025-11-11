use crate::parser::Model;
use anyhow::{Result, anyhow};
use std::collections::HashSet;

pub fn validate(model: &Model) -> Result<()> {
    // unique class names
    let mut class_names = HashSet::new();
    for c in &model.classes {
        if !class_names.insert(c.name.to_lowercase()) {
            return Err(anyhow!("Duplicate class name found: {}", c.name));
        }
        // attributes unique per class
        let mut attrs = HashSet::new();
        for a in &c.attributes {
            if !attrs.insert(a.name.to_lowercase()) {
                return Err(anyhow!("Duplicate attribute '{}' in class '{}'", a.name, c.name));
            }
        }
        // basic checks: attribute type exists
        for a in &c.attributes {
            if a.ty.trim().is_empty() {
                return Err(anyhow!("Attribute '{}' in class '{}' missing type", a.name, c.name));
            }
        }
    }
    Ok(())
}
